#ifndef REMAKE_CHANGES_H
#define REMAKE_CHANGES_H


#include <string>
#include <vector>
#include <queue>

using namespace std;

class Changes {
private:
    inline static string c_joined;
    inline static string c_left;
    inline static bool success = true;

public:

    static void set_cjoined(string c);

    /**
    * @brief Function to handle joining a user to a university class (UC).
    *
    * @param id The user's ID.
    * @param uc The target university class (UC).
    * @param cap The maximum capacity of the UC.
    * @param cc The current class (for undo operation).
    * @param sw A boolean indicating whether this is a switch operation.
    * @param undo A boolean indicating whether this is an undo operation.
    *
    * This function reads data from two CSV files, "students_classes.csv" and "classes_per_uc.csv," to determine
    * if the user can join the specified UC. It checks for schedule conflicts and available classes before making
    * the assignment. The function handles both normal and undo operations.
    */
    static void call_joinuc(const string& id, const string& uc, int cap, const string& cc = "", bool sw = false, bool undo = false);
    // Complexity analysis:
    // The complexity of this code can be broken down as follows:
    // - Reading and processing data from two CSV files has a time complexity of O(N) where N is the number of lines in the files.
    // - The two while loops that parse the CSV data have time complexity of O(N).
    // - The inner loops that iterate over the classes have time complexity of O(K) where K is the number of classes.
    // - The recursive calls to call_joinuc have an exponential time complexity in the worst case.
    // - Overall, the complexity is dependent on the number of lines in the CSV files and the number of classes, and it can be relatively high in the worst case.

    // Note: The actual time complexity may vary depending on the specific data and runtime conditions.

    static void set_cleft(string c);

    /**
    * @brief Function to handle a student leaving a university class (UC).
    *
    * @param id The user's ID.
    * @param uc The university class (UC) to leave.
    * @param ucj The university class (UC) to join (for swap operation).
    * @param clas_joined The class joined after the swap operation.
    * @param cap The maximum capacity of the UC.
    * @param trigger A boolean indicating a swap operation.
    * @param sw A boolean indicating a swap operation.
    * @param undo A boolean indicating an undo operation.
    *
    * This function reads and processes data from the "students_classes.csv" file to manage a student's enrollment in a UC.
    * It handles leave operations, swap operations, and undo operations.
    */
    static void call_leaveuc(const string& id, const string& uc, const string& ucj, const string& clas_joined, int cap, bool trigger = false, bool sw = false, bool undo = false);

    /**
    * @brief Function to perform a university class (UC) swap for a student.
    *
    * @param id The user's ID.
    * @param ucl The university class (UC) to leave.
    * @param ucj The university class (UC) to join.
    * @param cap The maximum capacity of the UC.
    *
    * This function allows a student to swap from one university class (ucl) to another (ucj). It first attempts to
    * join the target UC (ucj) using the "call_joinuc" function and checks for success. If the join operation is successful,
    * it proceeds to leave the current UC (ucl) using the "call_leaveuc" function. It then logs the swap operation using the
    * "write_log" function from the Undo class.
    */
    static void call_swapuc(const string& id, const string& ucl, const string& ucj, int cap);

    /**
    * @brief Function to perform a class swap for a student within the same university class (UC).
    *
    * @param id The user's ID.
    * @param uc The university class (UC) in which the swap will occur.
    * @param cap The maximum capacity of the UC.
    *
    * This function allows a student to swap from one class within the same university class (UC). It first attempts to join
    * the same UC using the "call_joinuc" function, indicating a swap operation. It checks for the success of the join operation.
    * If the join operation is successful, it proceeds to leave the same UC using the "call_leaveuc" function, indicating a swap operation.
    * It then logs the swap operation using the "write_log" function from the Undo class.
    */
    static void call_swapclass(const string& id, const string& uc, int cap);

    /**
    * @brief Perform multiple enrollment operations for a student based on user input.
    *
    * @param id The user's ID.
    * @param cap The maximum capacity for university classes.
    * @param operations A queue of enrollment operations to execute.
    *
    * This function allows a student to queue multiple enrollment operations and execute them in the desired order.
    * The user is prompted to choose operations, and the selected operations are added to a queue.
    * Once all operations are queued, the user can choose to execute the requests or cancel the whole operation.
    */
    static void call_multi(const string& id, int cap, queue<string> operations);

    static void execute_requests(queue<string> operations, const string& id, int cap);

    /**
     * @brief Filter and update a list of available classes for a University Class (UC).
     *
     * @param vect A vector containing the available classes for the UC.
     * @param uc The code of the University Class (UC).
     *
     * This function filters and updates the list of available classes for a specific UC. It compares the number of students
     * registered in each class and adjusts the list based on the given criteria.
     *
     * @param vect A reference to a vector that holds the available classes for the UC. This vector will be filtered and updated.
     * @param uc The code of the University Class (UC) for which class availability is determined.
     *
     * The function iterates through the available classes and calculates the number of students registered in each class
     * using the `Ocupation::check_class_occupation_per_uc` function. It identifies the class with the maximum and minimum
     * student counts and compares the difference.
     *
     * If the difference between the maximum and minimum student counts is 4, it removes the class with the maximum count from
     * the list and recursively calls itself to reevaluate the updated list.
     *
     * If the difference is greater than 4, it identifies all classes with the minimum student count, removes them from the
     * list, and sets the list to contain only these minimum student count classes.
     *
     * If the difference is less than or equal to 4, no further changes are made to the list, and the function returns.
     *
     * This function is useful for ensuring a balanced distribution of students among classes in a University Class (UC).
     */
    static void available_classes(vector<string> &vect,const string& uc);

    /**
     * @brief Check for schedule conflicts for a student enrolling in a class of a University Class (UC).
     *
     * @param cc The code of the class within the UC.
     * @param uc The code of the University Class (UC) where the class is located.
     * @param id The student's identifier.
     *
     * This function checks for schedule conflicts when a student attempts to enroll in a specific class of a University Class (UC).
     *
     * @param cc The code of the class within the UC for which the student is enrolling.
     * @param uc The code of the University Class (UC) where the class is located.
     * @param id The identifier of the student enrolling in the class.
     *
     * The function reads class schedules from both "students_classes.csv" and "classes.csv" files to check for conflicts.
     *
     * It first reads the schedule of the class the student is attempting to enroll in and stores it in the 'ra' vector.
     *
     * Then, it reads the schedule of the student from "students_classes.csv" and compares it with the schedule of the target class.
     * If any schedule conflicts are detected (e.g., overlapping time slots), the function returns `false`.
     *
     * If no conflicts are found, the function returns `true`, indicating that the student can enroll in the class without schedule conflicts.
     */
    static bool check_conflicts(const string& cc, const string& uc, const string& id);

};


#endif //REMAKE_CHANGES_H
