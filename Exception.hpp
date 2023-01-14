#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

// Generic class for exceptions
class Exception {
    private:
		std::string description_{"[Exception::Generic] Generic error"};
        
	public:
		// empty constructor with default value
		Exception(void) {}

		// constructor with error description as argument
		Exception(const std::string& description) {
			this->description_ = description;
		}

		// function member to get error description
		const std::string what(void) const {
			return this->description_;
		}
};

#endif