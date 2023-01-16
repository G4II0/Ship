#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

// Generic class for exceptions
class Exception {
    private:
		std::string description_;
        
	public:
		// empty constructor with default value
		Exception(void) {
			description_ = "[Exception::Generic] Generic error";
		}

		// constructor with error description as argument
		Exception(const std::string& description) {
			this->description_ = description;
		}

		// function member to get error description
		const std::string what(void) const {
			return this->description_;
		}
};

class invalidMoveException : public std::exception {
    private:
        std::string message_;
    public:
        invalidMoveException(const std::string &msg) : message_(msg) {}

        const char* what(void) const {
            return message_.c_str();
        }
};

#endif