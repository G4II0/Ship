#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

// Generic class for exceptions
class Exception {
    private:
		std::string message_;
        
	public:
		// empty constructor with default value
		Exception(void) {
			message_ = "[Exception::Generic] Generic error";
		}

		// constructor with error description as argument
		Exception(const std::string& description) {
			this->message_ = description;
		}

		// function member to get error description
		const std::string what(void) const {
			return this->message_;
		}
};

class invalidMoveException {
    private:
        std::string message_;
    public:
        invalidMoveException(const std::string &msg) : message_(msg) {}

        const std::string what(void) const {
            return message_;
        }
};

class invalidInputException {
    private:
        std::string message_;
    public:
        invalidInputException(const std::string &msg) : message_(msg) {}

        const std::string what(void) const {
            return message_;
        }
};

#endif