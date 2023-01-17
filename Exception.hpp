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

//eccezione mossa invalida
class InvalidMoveException {
    private:
        //variabile della classe
        std::string message_;
    public:
        //costruttore della classe
        InvalidMoveException(const std::string &msg) : message_(msg) {}

        //funzione membro che da la descrizione dell'errore
        const std::string what(void) const {
            return message_;
        }
};

//eccezione di un input errato
class InvalidInputException {
    private:
        //variabile della classe
        std::string message_;
    public:
        //costruttore
        InvalidInputException(const std::string &msg) : message_(msg) {}

        //funzione membro che da la descrizione dell'errore
        const std::string what(void) const {
            return message_;
        }
};

#endif