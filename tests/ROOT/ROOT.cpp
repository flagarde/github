#include "TFile.h"

int main()
{
  TFile file("Dumb.root","RECREATE");
  if(file.IsOpen()==kTRUE) return 0;
  else return 1;
}
