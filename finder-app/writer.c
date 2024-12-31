#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Open syslog with LOG_USER facility
    openlog(NULL, LOG_PERROR, LOG_USER);

    // Check if arguments are sufficient
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments. Usage: %s <file_path> <string>", argv[0]);
        closelog();
        return 1;
    }

    char *file_path = argv[1];
    char *string_to_write = argv[2];

    // Open file for writing
    FILE *file = fopen(file_path, "w");
    if (!file) {
        syslog(LOG_ERR, "Failed to open file %s for writing", file_path);
        closelog();
        return 1;
    }

    // Write string to file
    if (fprintf(file, "%s", string_to_write) < 0) {
        syslog(LOG_ERR, "Failed to write to file %s", file_path);
        fclose(file);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\"", string_to_write, file_path);

    // Close file and syslog
    fclose(file);
    closelog();
    return 0;
}
