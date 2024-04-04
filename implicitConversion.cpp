#include <iostream>
#include <string>

class Entity
{
  public:
     Entity(const std::string& name)
        : m_Name(name), m_Age(-1)
    {}

    Entity(int age)
        : m_Name("unknown"), m_Age(age)
    {}

  private:
    std::string m_Name;
    int m_Age;
};

void foo(const Entity& entity)
{
    std::cout << "something" << '\n';
}

int main()
{
    auto e = Entity(22);

    // Implicit conversion of 22 to Entity:
    Entity f = 22;

    // Implicit conversion 22 to Entity
    foo(22);

    auto g = Entity(std::string("Bob"));

    // Implicit conversion of std::string to Entity
    Entity h = std::string("Bob");

    // Implicit conversion of const char* to std::string
    auto i = Entity("Bob");

    // Implicit conversion of const char* to std::string to Entity 
    // (double conversion won't build):
 
    //Entity j = "Bob";
    //foo("Bob");

    foo(std::string("Bob"));

    return 0;
}

