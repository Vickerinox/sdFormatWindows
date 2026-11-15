#include "errors.h"
#include <string>


static std::string verboseErrorMessage(int error_code) {
    std::string message = std::string("Error code ");
    message += std::to_string(error_code);
    message += ":\n";

    switch(error_code) {
        case 0:
        message += "Formatting succeeded, however somehow it was still marked as an error.";
        break;
        case ERR_INVALID_ARG:
        message += "One or more of the options trying to be set are invalid. Check the drive label, capacity setting, and erase type.";
        break;
        case ERR_DEV_OPEN:
        message += "Failed to open the SD card. Please make sure to run sdFormatWindows with administrator privileges. Make sure your SD Card has a solid connection to your PC.";
        break;
        case ERR_DEV_TOO_SMALL:
        message += "The SD Card trying to be used is too small for this tool. Please use a bigger SD Card.";
        break;
        case ERR_ERASE:
        message += "Failed to erase the data on the SD Card. Please make sure to run sdFormatWindows with administrator privileges. Close any other applications which might be using the SD card.";
        break;
        case ERR_FORMAT_PARAMS:
        message += "An incompatible set of formatting options are being used together.";
        break;
        case ERR_PARTITION:
        message += "Failed to create a new MBR and Partition set. Make sure your SD Card is legitimate and has a solid connection to your PC.";
        break;
        case ERR_FORMAT:
        message += "Failed to create new filesystem. Make sure your SD Card has a solid connection to your PC.";
        break;
        case ERR_CLOSE_DEV:
        message += "Failed to eject the SD card. Please make sure no other programs are using the SD card.";
        break;
        case ERR_EXCEPTION:
        message += "An exception has occurred in the program.";
        break;
        case ERR_UNK_EXCEPTION:
        message += "An unknown exception has occurred in the program.";
        break;
        default:
        message += "An unknown error has occurred. Please report this to the developers via github.";
        break;
    }
    return message;
}