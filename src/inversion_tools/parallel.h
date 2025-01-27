#ifndef PARALLEL_H
#define PARALLEL_H

#ifdef _MPI
#include <mpi.h>
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include "sequential.h"

const double STOP_MESSAGE = -1;
const unsigned ILS_TASK_LEN = 10;
const unsigned ILS_RESULT_LEN = 20;

class CAMBALA_parallel : public CAMBALA_sequential
{
public:
	CAMBALA_parallel();
	~CAMBALA_parallel();
	int corecount;
	double mpi_start_time;
	void MPI_main();
private:
	void controlProcessIls();
	void computingProcessIls();
	void sendTaskIls(double *task, int task_index, const unsigned process_index, const vector<double> depths);

	void controlProcessBruteforce();
	void controlProcessFixedDepths(const vector<double> depths, const unsigned depths_index);
	void computingProcessBruteforce();
	
	void reportRecordPoint( search_space_point record_point, unsigned long long record_count );
};

#endif
