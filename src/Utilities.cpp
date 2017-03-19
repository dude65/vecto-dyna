//
// Created by ondra on 26.2.17.
//

#include "Utilities.h"

const char * ENV_HOME = "VECTO_HOME";

std::string getEnvironmentHome() {
    char * home = getenv(ENV_HOME);

    if (home == NULL) {
        home = ".";
    }

    return std::string(home);
}
