// AM5 example for std::vector
// compile command example
// g++ examples/console/main.cpp -o am5 -I src -std=c++11

#include <menu/def/console.h>
#include <menu/comp/vectorMenu.h>

MenuOut<Menu::ConsoleFmt<>::To<ConsoleOutDev<>>> consoleOut;

using Op=Prompt<Text>;

//using std::vector
Prompt<Menu::VectorMenuDef<Text>> mainMenu("Main menu"
  ,new Op("Op 1")
  ,new Op("Op 2")
  ,new Op("Op 3")
  ,new Op("on heap")
);

Op extra("extra option, dynamic add");

int main(int,const char**) {
  mainMenu.push_back(&extra);//append an option at runtime
  consoleOut.setTarget(mainMenu);
  consoleOut.printMenu();
  return 0;
}
