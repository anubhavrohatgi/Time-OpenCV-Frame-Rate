#include "AssessTime.h"

namespace vi {
	namespace Utility {

AssessTime::AssessTime(const std::string t) : title(t), counter(0)
{
	is_started = false;
	start_clock = 0;
	cumulative_clock = 0;
	n_starts = 0;
}


AssessTime::~AssessTime(void)
{
	if(is_started)
		std::cout<<"\nTimer named "<<title<<" is being destroyed\n";
}


void AssessTime::Start()
{
	if(is_started)
	{
		std::cout<<"\nTimer named "<<title<<" is already started\n";
		start_clock = cv::getTickCount();
		return;
	}
	
	is_started = true;
	n_starts++;
	start_clock = cv::getTickCount();
}


void AssessTime::Stop()
{
	if(!is_started)
	{
		std::cout<<"\nTimer named "<<title<<" was not started\n";
		return;
	}

	cumulative_clock += cv::getTickCount() - start_clock;
	is_started = false;
}


void AssessTime::Reset()
{
	if(is_started)
	{
		std::cout<<"\nTimer named "<<title<<" was started during reset request. Only reset cumulative time\n";
		return;
	}

	start_clock = 0;	
	cumulative_clock = 0;	
	n_starts = 0;
}


float AssessTime::elapsedTime() 
{
	if (is_started){
		std::cout<<"\nTimer is running. Cannot provide result !!! \n";
		return 0.0f;
	}
	float timeUsed = TimeInSeconds();
	
	printf("\n\t\t****Timer %s****\n",title.c_str());
	printf("\tTotal Time elapsed so far = %.3f sec\n",timeUsed);
	printf("\tTotal number of segments accounted for = %d",n_starts);
	printf("\n\tAvg Time per run = %.3f sec\n",timeUsed/n_starts);
	//std::cout<<"\n Timer "<<title<<"  Cumulative time = "<<timeUsed<<"  number of runs = "<<n_starts<<"  Avg Time Taken per run = "<<timeUsed/n_starts<<std::endl;

	return timeUsed/(float)n_starts;

}


float AssessTime::TimeInSeconds()
{
	if (is_started){
		std::cout<<"\nTimer "<<title<<" is still running\n";
		return 0;
	}
	return static_cast<float>(double(cumulative_clock) / cv::getTickFrequency());
}


/********For getting the FPS********/

void AssessTime::setupResetFPStimer()
{
	counter = 0;
}


void AssessTime::startFpsTimer()
{
	if(counter == 0 )
			time(&start);	
}



void AssessTime::processFPS()
{
	time(&end);
	counter++;

	sec = difftime(end,start);
	fps = counter/sec;
	
	if(counter == (ULONG_MAX - 1000))
		counter = 0;
}



double AssessTime::reportFPS()
{

	if(counter > 25)
		printf("%.2f fps\n",fps);

	return fps;
}


	}//end of namespace utility
}//end of namespace vi
