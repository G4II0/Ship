//https://stackoverflow.com/questions/35068566/define-an-error-class-for-c
//https://www.html.it/pag/64807/metodi-const/
//https://cplusplus.com/doc/tutorial/exceptions/

class InvalidInputException
{
        public:
        InvalidInputException();
        InvalidInputException(const exception&);
        exception& operator=(const exception&);
        virtual InvalidInputException();
        virtual const char* what() const;
};

// eccezione: mossa non valida
class InvalidMoveException
{
        public:
        InvalidMoveException();
        InvalidMoveException(const exception&);
        exception& operator=(const exception&);
        virtual InvalidMoveException();
        virtual const char* what() const;
};