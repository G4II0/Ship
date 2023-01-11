
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