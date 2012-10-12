/*****************************************************************************
 * SV_PairReader.h
 * (c) 2012 - Ryan M. Layer
 * Hall Laboratory
 * Quinlan Laboratory
 * Department of Computer Science
 * Department of Biochemistry and Molecular Genetics
 * Department of Public Health Sciences and Center for Public Health Genomics,
 * University of Virginia
 * rl6sf@virginia.edu
 *
 * Licenced under the GNU General Public License 2.0 license.
 * ***************************************************************************/

#ifndef __SV_PAIRREADER_H__
#define __SV_PAIRREADER_H__

#include <string>
#include <map>
using namespace std;

#include "SV_BreakPoint.h"
#include "SV_EvidenceReader.h"
#include "api/BamReader.h"
#include "api/BamAux.h"

#include "ucsc_bins.hpp"

using namespace BamTools;

//{{{struct pair_end_parameters {
struct pair_end_parameters {
	string bam_file,
		   histo_file;
	double mean, stdev;
	unsigned int read_length,
				 min_non_overlap,
				 discordant_z,
				 back_distance,
				 min_mapping_threshold;
	int weight;
	int id;
};
//}}}

class SV_PairReader : public SV_EvidenceReader
{
	private:
		string bam_file,
			   histo_file;
		double mean, stdev;
		unsigned int read_length,
					 min_non_overlap,
					 discordant_z,
					 back_distance,
					 min_mapping_threshold;
		int weight;
		int id;
		bool is_open,
			 have_next_alignment;

	public:
		BamAlignment bam;
		BamReader reader;
		map<string, BamAlignment> mapped_pairs;
		string header;
		RefVector refs;
		bool inited;

		SV_PairReader();
		SV_PairReader(struct pair_end_parameters pair_end_param);
		bool add_param(char *param, char *val);
		string check_params();
		struct pair_end_parameters get_pair_end_parameters();
#if 1
		void initialize();
		void set_statics();
		void process_input(UCSCBins<SV_BreakPoint*> &l_bin,
						   UCSCBins<SV_BreakPoint*> &r_bin);
		void process_input_chr(string chr,
							   UCSCBins<SV_BreakPoint*> &l_bin,
							   UCSCBins<SV_BreakPoint*> &r_bin);
		void terminate();
		string get_curr_chr();
		bool has_next();
#endif
};

#endif
