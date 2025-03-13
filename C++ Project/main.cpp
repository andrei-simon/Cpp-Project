#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "FileRepository.h"
using namespace std;
int main() {
    test_all();
    fileRepo fRepo("Parking.txt");
    Service service(fRepo);
    UI ui(service);
    ui.run();
    return 0;
}
