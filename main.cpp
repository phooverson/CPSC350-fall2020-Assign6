#include "Assign6.h"
using namespace std;

int main(int argc, char** argv){
  ManageSort *manageSort = new ManageSort();
  manageSort->ReadFile(argv[1]);
  manageSort->runSort();
  delete manageSort;
}
