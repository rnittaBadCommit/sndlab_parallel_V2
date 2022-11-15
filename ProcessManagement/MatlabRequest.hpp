#ifndef MATLAB_REQUEST_HPP
# define MATLAB_REQUEST_HPP

# include <iostream>
# include <vector>
# include <map>
# include <deque>

namespace rnitta
{


class MatlabRequest
{
	public:
		// typedef
			typedef int t_Eb;
			typedef std::vector<int, t_Eb> t_Eb_vec;
			typedef std::map<const std::string, const std::string> t_request_info;

		// canonical
			MatlabRequest();
			MatlabRequest( const MatlabRequest& other );
			~MatlabRequest();
			MatlabRequest& operator=( const MatlabRequest& other );

		// getter & setter
			const t_Eb_vec& get_Eb_vec() const;
			const t_request_info& get_request_info() const;
			void set_Eb_vec( const t_Eb_vec& eb_vec );
			void set_request_info( const t_request_info& request_info );

	private:
		t_Eb_vec eb_vec_;
		t_request_info request_info_;

};	// class MatlabRequest


}	// namespace rnitta

#endif
