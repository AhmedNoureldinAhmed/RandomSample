#include <iostream>
#include <random>  // Random Function
#include <ctime>   // Time Function


using namespace std;

// initialized Start and End Point For Random Number
size_t _start,_end;

int _random(size_t,size_t);

unsigned* RandomSample(unsigned [],size_t,size_t);

void print(unsigned [],size_t );



int main()
{

 size_t sizeP{20},sizeS{10};

 unsigned  p[sizeP]{1,2,99,4,5,6,7,8,9,10,11,112,13,14,15,16,17,18,19,200}, sample[sizeS]{};

 cout<<"Enter interval Random"<<endl<<"From : " ;
 cin >>_start;
 cout<<"To : ";
 cin>>_end;


 RandomSample(p,sizeP,sizeS);

}


int _random()
{

                    // From Random library
  static std::default_random_engine e{time(NULL)};      // Define Engine Random
  static std::uniform_int_distribution<int> d{(_start), (_end)};  // Define uniform integer Distribution
                                                        //Note =>time(NULL) To Skip Replication Every Run
    return d(e);
 // Method (2) return (rand()%20+1);
}



 unsigned* RandomSample(unsigned population[],size_t nPop,size_t nSample){

 unsigned sample[nSample]{}; // Define Empty Array to Take Samples

            // Assigned Random Population to Sample
 for(size_t i=0; i < nSample; i++ )
    {
            sample[i]=population[_random()];
    }

            // Catch Repeat Sample
  for(size_t i=0; i < nSample; i++ )
   {
         for(size_t j=0; j < nSample; j++ )
        {
            if (i == j )  {continue;} // Skip Sample[0] == Sample [0] etc..
            else { if (sample[i] == sample[j]) {sample[j] = population[_random()];}} // Replace RepeatSamples
        }
 }
        // Print Sample
     print(sample,nSample);


  return sample;
 }

void print(unsigned sample[],size_t nSample){for(size_t i=0; i < nSample; i++ )  cout<<sample[i]<<endl;}
