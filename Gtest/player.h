

class Player
{
        Button* button;
public:
        Player( Button* turtle )
                :       button(turtle){}

        bool DrawCircle(int, int, int){
                button->release();
                return true;
        }
};
