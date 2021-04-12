enum lines
{
    NOLINE,
    SINGLELINE,
    DOUBLELINE
};
enum modes
{
    NOMODE,
    INT_FLOAT,
    INT_INT_INT
};
enum paramaters
{
    ELEMENTE_LENGHT,
    THERMAL_CONDUCTIVITY,
    HEAT_SOURCE
};

class item
{
protected:
    int id;
    float x;
    int node1;
    int node2;
    float value;

public:
    int getId()
    {
        return id;
    }
    float getX(){
        return x;
    }
    int getNodel(){
        return node1;
    }
    int getNode2(){
        return node2;
    }
    float getValue(){
        return value;
    }

    virtual void setIntFloat (int n, float r) = 0;
    virtual void setIntIntInt(int n1, int n2, int n3) = 0;
};

class node: public item{
public:
    void setIntFloat(int identifier, float x_coordinate){
        id = identifier;
        x = x_coordinate;
    }
    void setIntIntInt(int n1, int n2, int n3){
        
    }
};