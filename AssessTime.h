#pragma once

#include <iostream>
#include <assert.h>
#include <time.h>
#include <limits>
#include <opencv2\core\core.hpp>


namespace vi {
	namespace Utility {
	
typedef unsigned int uint;
typedef unsigned long int ulint;

//! Times The Code
/*!
  * The class is used to get the time of processing a code snippet. 
  * After initializing the class you just need to place the Start and Stop fns and get the 
  * time elapsed by using the respective function.
  * This class object can be reused in the code for example 
  * 
  *		vi::Utility::AssessTime tik;
  *		tik.Start();
  *		....	
  *		....	
  *		tik.Stop();
  *		...
  *		...
  *		tik.Start();
  *		...
  *		...
  *		tik.Stop();
  *		tik.elapsedTime();
  *
  *	So in this there is no need to reset time, This class does it automatically and 
  * gives a detailed report of runtime of the various sections of the code together 
  * with the total running time.
  */
class AssessTime
{
public:

	/*!
                 \fn   AssessTime(const std::string t = "TimerDefault")				 
                 \brief instantiates the object of the class.          
				 \param t Assigns the name of the timer
    */
	AssessTime(const std::string t = "TimerDefault");


	/*!
                 \fn    ~AssessTime(void)
                 \brief Destroys the class objects.
    */
	~AssessTime(void);


	/*!
                 \fn    Start()
                 \brief Starts the timer.
    */
	void Start();
	
	
	
	/*!
                 \fn    Stop()
                 \brief Stops the timer.
    */
	void Stop();
	
	
	
	/*!
                 \fn    Reset()
                 \brief Resets the timer.
    */
	void Reset();


	/*!
                 \fn    elapsedTime()
                 \brief Does not Stop the timer automatically,Hence to provide the elapsed time stop it maually.
						Gives a summary of time assessed in the segments of the code as well as the total time of flight.
						Time is in seconds.
    */
	float elapsedTime();


	/*!
                 \fn    stopAndgetTime()
                 \brief Stops the timer and returns the time from elapsedTime() .
    */
	float stopAndgetTime() { Stop(); return elapsedTime();}
	
	
	
	/*!
                 \fn    TimeInSeconds()
                 \brief Converts milliseconds to seconds.
    */
	float TimeInSeconds();



	/*!
                 \fn    AvgTime()
                 \brief Calculates the average time taken by all the code segments where indicated.
    */
	float AvgTime(){assert(is_started == false); return TimeInSeconds()/n_starts;}




	/*!
                 \fn    setupResetFPStimer()
                 \brief Initializes the fps timer. Put this function just before the while/for loop.
						This fucntions resets the FPS timer counter.
    */
	void setupResetFPStimer();



	/*!
                 \fn    startFpsTimer()
                 \brief Starts the timer to get the fps.
						The function should be placed in the for/while loop just above where you get the frames.
    */
	void startFpsTimer();




	/*!
                 \fn    processFPS()
                 \brief The function should be placed just before the curly braces of the for/while loop. 
						This function processes the current FPS. Best results after 25 frames have passed.
						
    */
	void processFPS();


	/*!
                 \fn    reportFPS()
                 \brief Reports the current average fps. Prints the fps inline with the loop.
						For best results and optimization using he printf instead of cout statements.
    */
	double reportFPS();




private:

	const std::string title;

	bool is_started;

	uint64 start_clock;
	uint64 cumulative_clock;
	uint n_starts;


	time_t start;
	time_t end;
	ulint counter;
	double sec;
	double fps;

};

	}//end of namespace utility

}//end of namespace vi
