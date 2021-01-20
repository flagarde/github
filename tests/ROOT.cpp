#include "TFile.h"

int main()
{
  TFile file("Dumb.root","RECREATE");
  return file.IsOpen();
}
