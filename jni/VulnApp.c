#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void foo(char *input) {
    char buf[15];

    strcpy(buf, input);
    printf("%s", buf);

    return;
}

JNIEXPORT jint JNICALL Java_sqlab_craxdroid_vulnapp_VulnApp_main
  (JNIEnv *env, jclass class) {
    int file;
    struct stat buffer;
    int status;
    char* buf;

    file = open("/data/local/tmp/input", O_RDONLY);
    status = fstat(file, &buffer);

    __android_log_print(ANDROID_LOG_VERBOSE, "VulnApp",
            "File size: %d\n", buffer.st_size);

    buf = (char*) malloc(buffer.st_size);
    if (buf != NULL) {
        int n = 0;
        if ((n = read(file, buf, buffer.st_size)) > 0) {
            __android_log_print(ANDROID_LOG_VERBOSE, "VulnApp",
                    "Read size: %d\n", n);
            foo(buf);
        }
        free(buf);
    }

    close(file);

    return 0;
}

