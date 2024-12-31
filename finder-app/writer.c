#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Initialize syslog with LOG_USER facility
    openlog("writer", LOG_PID, LOG_USER);

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments required - <writefile> and <writestr>");
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Could not open file %s for writing: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: Could not open file %s for writing: %s\n", writefile, strerror(errno));
        closelog();
        exit(1);
    }

    // Write the string to the file
    if (fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error: Failed to write to file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: Failed to write to file %s: %s\n", writefile, strerror(errno));
        fclose(file);
        closelog();
        exit(1);
    }

    // Log the success message
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);
    printf("Successfully wrote to %s\n", writefile);

    // Close the file and syslog
    fclose(file);
    closelog();

    return 0;
}
