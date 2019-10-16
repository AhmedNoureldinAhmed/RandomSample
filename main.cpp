#include <iostream>
#include <random>
#include <ctime>


using namespace std;

int _random()
{

  // time(NULL) To Skip Replication
  static std::default_random_engine e{time(NULL)};   // Define Engine Random
  static std::uniform_int_distribution<int> d{0, 9};  // Define uniform integer Distribution

return d(e);
 }

 unsigned RandomSample(unsigned *population,size_t nPop,size_t nSample){

    unsigned sample[nSample]{};

 for(size_t i=0; i < nSample; i++ )
   {

      sample[i]=population[_random()]; /*

       Assigned (From Population To Random Sample )

       */

  }
  return *sample;
 }


int main()
{

 size_t sizeP{10},sizeS{5};

 unsigned  p [sizeP]{75,55,85,130,90,22,70,55,30,98}, sample[sizeS]{};

     for(size_t i=0; i < sizeS; i++ )
   {

      cout<<RandomSample(p,sizeP,sizeS)<<endl;

  }

}
