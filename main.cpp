#include <iostream>
#include <random>  // Random Function
#include <ctime>   // Time Function
#include<vector>   // Vector Containers


using namespace std;

// initialized Start and End Point For Random Number
size_t _start,_end;

int _random();

unsigned RandomSample(vector <unsigned>&,size_t);

void print(vector<unsigned>&);


int main()
{

vector<unsigned> pop{};
unsigned input{};

 cout<<"Enter Population -- Insert 0 When Finished Population" <<endl;

 while (true)
 {
      cin>>input;
        if (input ==0) {break;}
            pop.push_back(input); //insert Population to Vector
}
    if(pop.empty()) // if no Population
    {
        cout<<"No Population to Sort"<<endl;
        return 0;
    }

size_t sizeS{};
cout<<"Enter Size of Sample " <<endl;
 cin>>sizeS;
    if (sizeS > pop.size())
    {
        cout<<"Number of Sample less than Population"<<endl;
        return 0;
    }

cout<<"Enter interval Random"<<endl<<"From : " ;
 cin >>_start;
cout<<"To : ";
 cin>>_end;

// Start Function
RandomSample(pop,sizeS);

return 0;

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



unsigned RandomSample(vector<unsigned> &population,size_t nSample)
{

 vector<unsigned> sample(nSample); // Define Empty Array to Take Samples

            // Assigned Random Population to Sample
 for(size_t i=0; i < sample.size(); i++ )
{
      sample[i]=population[_random()];
}

            // Catch Repeat Sample
  for(size_t i=0; i < sample.size(); i++ )
   {
         for(size_t j=0; j < sample.size(); j++ )
        {
            if (i == j )  {continue;} // Skip Sample[0] == Sample [0] etc..
            else { if (sample[i] == sample[j]) {sample[j] = population[_random()];}} // Replace RepeatSamples
        }
 }
   // Print Sample
    print(sample);

  return 0;
 }

void print(vector<unsigned> &sample)
{
    cout<<"Sample is "<<endl;
    for(size_t i=0; i < sample.size(); i++ )
        cout<<sample[i]<<endl;
}
