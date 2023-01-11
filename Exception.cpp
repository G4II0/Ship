//https://stackoverflow.com/questions/35068566/define-an-error-class-for-c
//https://www.html.it/pag/64807/metodi-const/
//https://cplusplus.com/doc/tutorial/exceptions/

class InvalidInputException
        {
                std::string InvalidInputException() const
                {
                        return "Input non valido";
                }
        };
        // eccezione: mossa non valida
        class InvalidMoveException
        {
                std::string InvalidMoveException() const
                {
                        return "Mossa non valida";
                }
        };