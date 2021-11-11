#include <iostream>

class Grinder
{
private:
    int grindConsistencyLevel;
public:
    Grinder()
    {
        printf("Debug: Grinder - default constructor\n");
        grindConsistencyLevel = 2;
    }
    Grinder(int level)
    {
        printf("Debug: Grinder - constructor with parameters\n");
        grindConsistencyLevel = level;
    }
    Grinder(Grinder& grinder)
    {
        printf("Debug: Grinder - copy constructor\n");
        grindConsistencyLevel = grinder.getGrindConsistencyLevel();
    }
    ~Grinder()
    {
        printf("Debug: Grinder - destructor\n");
    }

    void setGrindConsistencyLevel(int level)
    {
        printf("Debug: Grinder::setGrindConsistencyLevel()\n");
        if (level <= 0) grindConsistencyLevel = 1;
        else if (level > 5) grindConsistencyLevel = 5;
        else grindConsistencyLevel = level;
    }
    int getGrindConsistencyLevel()
    {
        printf("Debug: Grinder::getGrindConsistencyLevel()\n");
        return grindConsistencyLevel;
    }
    void grind()
    {
        printf("Debug: Grinder::grind()\n");
        printf("Br");
        for (int i = 0; i < grindConsistencyLevel; i++)
        {
            printf("rr");
        }
        printf("\n");
    }
};

class CoffeeMachine
{
private:
    Grinder* grinder;
public:
    CoffeeMachine()
    {
        printf("Debug: CoffeeMachine - default constructor\n");
        grinder = new Grinder();
    }
    CoffeeMachine(int grindConsistencyLevel)
    {
        printf("Debug: CoffeeMachine - constructor with parameters\n");
        grinder = new Grinder(grindConsistencyLevel);
    }
    CoffeeMachine(CoffeeMachine& coffeeMachine)
    {
        printf("Debug: CoffeeMachine - copy constructor\n");
        grinder = new Grinder(coffeeMachine.getGrinderSettings());
    }
    ~CoffeeMachine()
    {
        printf("Debug: CoffeeMachine - destructor\n");
        delete grinder;
    }
    
    void setGrinderSettings(int grindConsistencyLevel)
    {
        printf("Debug: CoffeeMachine::setGrinderSettings()\n");
        grinder->setGrindConsistencyLevel(grindConsistencyLevel);
    }
    int getGrinderSettings()
    {
        printf("Debug: CoffeeMachine::getGrinderSettings()\n");
        return grinder->getGrindConsistencyLevel();
    }
    void makeCoffee()
    {
        printf("Debug: CoffeeMachine::makeCoffee()\n");
        grinder->grind();
        printf("Brewing coffee...\n");
        printf("Coffee is ready to be served\n");
    }


};

int main()
{
    CoffeeMachine* coffeeMachine = new CoffeeMachine(5);
    coffeeMachine->makeCoffee();
    delete coffeeMachine;
}
