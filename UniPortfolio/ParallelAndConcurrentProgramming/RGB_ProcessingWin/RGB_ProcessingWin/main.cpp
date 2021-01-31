#include <iostream>
#include <vector>
//Thread building blocks library
#include <tbb/task_scheduler_init.h>

//Wasen't included for some reason:
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <tbb/blocked_range2d.h>

//Others that wern't included:
#include <cstdlib>
#include <math.h>
#include <random>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
using namespace std::chrono;

//Free Image library
#include <FreeImagePlus.h>

using namespace std;
using namespace tbb;

int main()
{
    int nt = task_scheduler_init::default_num_threads();
    task_scheduler_init T(nt);

    //Part 1 (Greyscale Gaussian blur): -----------DO NOT REMOVE THIS COMMENT----------------------------//

	// Loads images
	fipImage loadImagePart1;
	loadImagePart1.load("../Images/render_1.png");
	loadImagePart1.convertToFloat();

	auto widthPart1 = loadImagePart1.getWidth();
	auto heightPart1 = loadImagePart1.getHeight();
	const float* const inputBuffer = (float*)loadImagePart1.accessPixels();

	// Setting up save image
	fipImage saveImagePart1;
	saveImagePart1 = fipImage(FIT_FLOAT, widthPart1, heightPart1, 32);
	float *outputBuffer = (float*)saveImagePart1.accessPixels();

	// Get total array size
	uint64_t numberOfPixelsInImagePart1 = widthPart1 * heightPart1;

	// Divide processing into 4 blocks by default
	uint64_t stepSize = numberOfPixelsInImagePart1 >> 2;

	//	Test sequential vs. parallel_for versions - run test multiple times and track speed-up
	double meanSpeedup = 0.0f;
	uint64_t numTests = 50;
	
	for (uint64_t testIndex = 0; testIndex < numTests; ++testIndex) {
			
		//	Setup image outputbuffer
		auto sLambda = [=](uint64_t i)->void {

			outputBuffer[i] = 1.0f - inputBuffer[i];
		};

		//	Start timer to measure the time for the sequential approach
		auto st1 = high_resolution_clock::now();

		for (uint64_t i = 0; i < numberOfPixelsInImagePart1; ++i)
			sLambda(i);

		//----Sequential approach----
		for (int y = 0; y < heightPart1; y++)
		{
			for (int x = 0; x < widthPart1; x++)
			{
				outputBuffer[x, y] = inputBuffer[x - 1, y - 1] * (1.0f / 16.0f) + inputBuffer[x, y - 1] * (2.0f / 16.0f) + inputBuffer[x + 1, y - 1] * (1.0f / 16.0f)
					+ inputBuffer[x - 1, y] * (2.0f / 16.0f) + inputBuffer[x, y] * (4.0f / 16.0f) + inputBuffer[x + 1, y] * (2.0f / 16.0f)
					+ inputBuffer[x - 1, y + 1] * (1.0f / 16.0f) + inputBuffer[x, y + 1] * (2.0f / 16.0f) + inputBuffer[x + 1, y + 1] * (1.0f / 16.0f);
			}
		}

		auto st2 = high_resolution_clock::now();

		auto st_dur = duration_cast<microseconds>(st2 - st1);
		std::cout << "sequential negative operation took = " << st_dur.count() << "\n";

		//----Parallel  approach----
		auto pt1 = high_resolution_clock::now();
	
		//----Gaussian blur----
		tbb::parallel_for(blocked_range2d<uint64_t, uint64_t>(0, heightPart1, 8, 0, widthPart1, widthPart1 >>2), [=](const blocked_range2d<uint64_t, uint64_t>& r) {

			auto y1 = r.rows().begin();
			auto y2 = r.rows().end();
			auto x1 = r.cols().begin();
			auto x2 = r.cols().end();

			for (uint64_t y = y1; y < y2; y++) {
				for (uint64_t x = x1; x < x2; x++)
				{
					outputBuffer[x, y] = (inputBuffer[x - 1, y - 1] * (1.0f / 16.0f)) + (inputBuffer[x, y - 1] * (2.0f / 16.0f)) + (inputBuffer[x + 1, y - 1] * (1.0f / 16.0f))
						+ (inputBuffer[x - 1, y] * (2.0f / 16.0f)) + (inputBuffer[x, y] * (4.0f / 16.0f)) + (inputBuffer[x + 1, y] * (2.0f / 16.0f))
						+ (inputBuffer[x - 1, y + 1] * (1.0f / 16.0f)) + (inputBuffer[x, y + 1] * (2.0f / 16.0f)) + (inputBuffer[x + 1, y + 1] * (1.0f / 16.0f));
				}
			}
		});

		auto pt2 = high_resolution_clock::now();
		auto pt_dur = duration_cast<microseconds>(pt2 - pt1);
		std::cout << "parallel negative operation took = " << pt_dur.count() << "\n";

		double speedup = double(st_dur.count()) / double(pt_dur.count());
		std::cout << "Test " << testIndex << " speedup = " << speedup << endl <<endl;

		meanSpeedup += speedup;
	}

	meanSpeedup /= double(numTests);
	std::cout << "Mean speed up = " << meanSpeedup << endl << endl;

	std::cout << "Saving grey_blurred image...\n";

	saveImagePart1.convertToType(FREE_IMAGE_TYPE::FIT_BITMAP);
	saveImagePart1.convertTo24Bits();
	saveImagePart1.save("grey_blurred.png");

	std::cout << "grey_blurred.png successfully saved" << endl;

    //Part 2 (Colour image processing): -----------DO NOT REMOVE THIS COMMENT----------------------------//

	// Input image data
	fipImage loadFirstImagePart2;
	loadFirstImagePart2.load("../Images/render_1.png");

	// Load a second image
	fipImage loadSecondImagePart2;
	loadFirstImagePart2.load("../Images/render_2.png");

	unsigned int widthPart2 = loadFirstImagePart2.getWidth();
	unsigned int heightPart2 = loadFirstImagePart2.getHeight();

	// Output image array
	fipImage saveImagePart2;
	saveImagePart2 = fipImage(FIT_BITMAP, widthPart2, heightPart2, 24);

	//	2D Vector that contains the RGB colour data of an image
	vector<vector<RGBQUAD>> rgbValues;
	rgbValues.resize(heightPart2, vector<RGBQUAD>(widthPart2));

	//----parallel_for that computes the Values of the absolute differences between the two images----
	tbb::parallel_for(blocked_range2d<int, int>(0, heightPart2, 0, widthPart2), [&](const blocked_range2d<int, int>&r) {
		auto y1 = r.rows().begin();
		auto y2 = r.rows().end();
		auto x1 = r.cols().begin();
		auto x2 = r.cols().end();

		//FreeImage structures to contain RGB data of every pixel
		RGBQUAD rgb;
		RGBQUAD rgb2;

		for (auto y = y1; y < y2; y++) {
			for (auto x = x1; x < x2; x++) {
				loadFirstImagePart2.getPixelColor(x, y, &rgb);
				loadSecondImagePart2.getPixelColor(x, y, &rgb2);

				rgbValues[y][x].rgbRed = abs(rgb.rgbRed - rgb2.rgbRed);
				rgbValues[y][x].rgbBlue = abs(rgb.rgbBlue - rgb2.rgbBlue);
				rgbValues[y][x].rgbGreen = abs(rgb.rgbGreen - rgb2.rgbGreen);
			}
		}
	});

	//----Second parallel_for to compute a simple binary threshold operation to make all of the pixels that aren't block into white----
	tbb::parallel_for(blocked_range2d<int, int>(0, heightPart2, 0, widthPart2), [&](const blocked_range2d<int, int>&r) {
		auto y1 = r.rows().begin();
		auto y2 = r.rows().end();
		auto x1 = r.cols().begin();
		auto x2 = r.cols().end();

		for (auto y = y1; y < y2; y++) {
			for (auto x = x1; x < x2; x++) {
				if (!(rgbValues[y][x].rgbRed == 0 && rgbValues[y][x].rgbBlue == 0 && rgbValues[y][x].rgbGreen == 0))
				{
					rgbValues[y][x].rgbGreen = 255;
					rgbValues[y][x].rgbBlue = 255;
					rgbValues[y][x].rgbRed = 255;
				}
				saveImagePart2.setPixelColor(x, y, &rgbValues[y][x]);
			}
		}
	});

	//	Saving output
	saveImagePart2.save("RGB_processed.png");

	std::cout << "RGB_processed.png successfully saved" << endl;

	//----Counts the number of white pixels in the image and works out the percentage of total white pixels----
	int numWhitePixels = 0;
	int totalNumPixels = 0;

	tbb::parallel_for(blocked_range2d<int, int>(0, heightPart2, 0, widthPart2), [&](const blocked_range2d<int, int>&r) {
		auto y1 = r.rows().begin();
		auto y2 = r.rows().end();
		auto x1 = r.cols().begin();
		auto x2 = r.cols().end();

		for (auto y = y1; y < y2; y++) {
			for (auto x = x1; x < x2; x++) {
				if (rgbValues[y][x].rgbRed == 255 && rgbValues[y][x].rgbBlue == 255 && rgbValues[y][x].rgbGreen == 255)
				{
					numWhitePixels++;
				}
				totalNumPixels++;
			}
		}
	});
	double percentageOfWhitePixels = (double)numWhitePixels * (100 / (double)totalNumPixels);

	cout << endl;
	cout << "The total number of white pixels: " << numWhitePixels << endl;
	cout << "Total number of pixels: " << totalNumPixels << endl;
	cout << "Total percentage of white pixels: " << percentageOfWhitePixels << endl << endl;

	//---Randomly place a red pixel on the image----
	srand(time(NULL));

	int yRand = rand() % heightPart2;
	int xRand = rand() % widthPart2;

	rgbValues[yRand][xRand].rgbGreen = 0;
	rgbValues[yRand][xRand].rgbBlue = 0;
	rgbValues[yRand][xRand].rgbRed = 255;

	saveImagePart2.setPixelColor(xRand, yRand, &rgbValues[yRand][xRand]);

	//----Search for an red pixels that have been placed in the image----
	tbb::parallel_for(blocked_range2d<int, int>(0, heightPart2, 0, widthPart2), [&](const blocked_range2d<int, int>&r) {
		int redDots = 0;
		auto y1 = r.rows().begin();
		auto y2 = r.rows().end();
		auto x1 = r.cols().begin();
		auto x2 = r.cols().end();

		for (auto y = y1; y < y2; y++) {
			for (auto x = x1; x < x2; x++) {
				if (rgbValues[y][x].rgbRed == 255 && rgbValues[y][x].rgbBlue == 0 && rgbValues[y][x].rgbGreen == 0)
				{
					cout << "Red dot is at these coordinates:" << endl;
					std::cout << "Y: " << y << endl;
					std::cout << "X: " << x << endl;
					redDots++;
				}
			}
		}
	});

	//----End of programme----
	std::cout << endl << "Programme complete!" << endl; //Indicates when the programme is done
	std::cin.get();
	std::cin.ignore();
	return 0;
}