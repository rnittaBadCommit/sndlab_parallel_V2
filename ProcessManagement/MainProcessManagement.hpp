#ifndef MAIN_PROCESS_MANAGEMENT_HPP
# define MAIN_PROCESS_MANAGEMENT_HPP

# include <iostream>
# include <vector>
# include <map>
# include <deque>
# include "MatlabRequest.hpp"

namespace rnitta
{


class MainMatlabRequestManagement
{
    public:
        // typedef
            typedef int t_requestID;
            typedef int t_Eb;
            typedef std::vector<int, t_Eb> t_Eb_vec;
            typedef std::map<t_requestID, t_Eb_vec> t_Eb_vec_map;
            typedef std::map<const std::string, const std::string> t_request_info;

        // canonical
            MainMatlabRequestManagement();
            MainMatlabRequestManagement( const MainMatlabRequestManagement& other );
            ~MainMatlabRequestManagement();
            MainMatlabRequestManagement& operator=( const MainMatlabRequestManagement& other );

        // setter and getter
            void addMatlabRequest( const t_requestID requestID, const MatlabRequest& request );



    private:
        t_Eb_vec_map    eb_vec_map_;
        std::map<t_requestID, MatlabRequest> request_map_;



};  // class ProcessManagement


}   // namespace rnitta

#endif
