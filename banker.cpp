#include <iostream>     // cout, cin
#include <vector>       // vector
using VEC_INT = std::vector<int>;
using VEC_BOOL = std::vector<bool>;
using MAT = std::vector<std::vector<int>>;

/***************** OVERLOADED OPERATORS *****************/

// Add 2 vectors
VEC_INT operator+(VEC_INT vec1, VEC_INT vec2) {
    VEC_INT sum(vec1.size());

    for (int i = 0; i < vec1.size(); i++) {
        sum[i] = vec1[i] + vec2[i];
    }

    return sum;
}

// Add 2 matrices
MAT operator+(MAT mat1, MAT mat2) {
    MAT sum(mat1.size(), std::vector<int>(mat1[0].size()));

    for (int i = 0; i < mat1.size(); i++) {
        sum[i] = mat1[i] + mat2[i];
    }

    return sum;
}

// Subtract 2 matrices
MAT operator-(MAT mat1, MAT mat2) {
    MAT diff(mat1.size(), std::vector<int>(mat1[0].size()));
    int x = mat1.size();

    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat1[i].size(); j++) {
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    return diff;
}

// Print all values for a single integer vector
std::ostream &operator<<(std::ostream &out, VEC_INT vec) {

    for (auto num: vec) out << num << ' ';
    out << '\n';

    return out;
}

// Print all values for a single boolean vector
std::ostream &operator<<(std::ostream &out, VEC_BOOL vec) {

    for (auto val: vec) out << val << ' ';
    out << '\n';

    return out;
}

// Print all values for a single matrix
std::ostream &operator<<(std::ostream &out, MAT matrix) {
    for (auto row: matrix) out << row;
    out << '\n';

    return out;
}

/***************** FUNCTIONS *****************/
// Test for one process
bool safetyAlgo(VEC_INT p_alloc, VEC_INT p_need, VEC_INT &work) {
    // Debugging
    std::cout << "Starting work vector: " << work;

    // Test need <= work
    if (p_need <= work) {
        std::cout << "Request accepted.\n";
        work = work + p_alloc;
    } else {
        std::cout << "Request denied - performing would leave the system in an unsafe state.\n";
        return false;
    }

    // Debugging
    std::cout << "Work vector after Process: " << work;
    return true;
}

// Test if there are any processes left to run
bool testAllDone(VEC_BOOL isDoneVec) {
    for (auto procDone: isDoneVec) {
        if (!procDone) return false;
    }

    return true;
}

// Dump all matrices
void dump(MAT MAX, MAT ALLOC, MAT NEED, VEC_INT AVAIL) {
    std::cout << "MAX matrix:\n" << MAX;
    std::cout << "ALLOCATION matrix:\n" << ALLOC;
    std::cout << "NEED matrix:\n" << NEED;

    std::cout << "AVAILABLE vector:\n" << AVAIL;
    std::cout << std::endl;
}

/*************************************************/
/***************** MAIN FUNCTION *****************/
/*************************************************/

int main(int argc, char* argv[]) {
    if (argc != 3) {    
        std::cout << "Malformed request.\n";
        std::cout << "Usage: " << argv[0] << " <num_processes> <num_rsrc_types> <> <>\n" << std::endl;
        return 1;
    }

    int n = atoi(argv[1]), m = atoi(argv[2]);   // n_processes, m_rsrcTypes

    if ((n < 1) || (m < 1)) {    
        std::cout << "Malformed request.\n";
        std::cout << "Value for <num_processes> and <num_rsrc_types> cannot be less than 1.";
        return 1;
    }


    /****************Placeholder for Arg values****************/
    // Example from slides
    MAT MAX = {             // Max matrix (n x m matrix)
               {7, 5, 3},
               {3, 2, 2},
               {9, 0, 2},
               {2, 2, 2},
               {4, 3, 3},
              };

    MAT ALLOC = {           // Allocation matrix (0 n x m matrix)
                 {0, 1, 0},
                 {2, 0, 0},
                 {3, 0, 2},
                 {2, 1, 1},
                 {0, 0, 2}
                };


    MAT NEED = MAX - ALLOC;

    VEC_INT AVAIL = {3, 3, 2}; // Available vector
    /**********************************************************/

    dump(MAX, ALLOC, NEED, AVAIL);

    VEC_BOOL isDoneVec(n, false);
    bool isFinished = false;

    int proc;
    VEC_INT work = AVAIL;
    while ((!isFinished) && (proc != -1)) {
        std::cout << "What process? ";
        std::cin >> proc;

        if ((proc < -1) || (proc >= n)) std::cout << "Invalid request - value must be between 0 and " << n-1 << " inclusive.\n";
        else if (isDoneVec[proc]) std::cout << "Process has already been completed.\n";
        else if (proc != -1) {
            std::cout << "Request vector? ";
            VEC_INT request = {1, 0, 2};
            std::cout << request << '\n';

            // Request acceptable?
            std::cout << "Work vector:\n" << work << '\n';

            bool isSafe = safetyAlgo(ALLOC[proc], NEED[proc], work);
            if (isSafe) isDoneVec[proc] = true;
            isFinished = testAllDone(isDoneVec);

            dump(MAX, ALLOC, NEED, AVAIL);

        }

        std::cout << "Completed processes (boolean): " << isDoneVec;
    }

    dump(MAX, ALLOC, NEED, AVAIL);
    std::cout << "Done." << std::endl;
    return 0;
}