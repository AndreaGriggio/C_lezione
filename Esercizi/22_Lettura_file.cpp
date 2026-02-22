#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include <deque>
using namespace std;
struct student{
    int id;
    string esame;
    int cfu;
    string data;
};

student parseStudent(const std::string& line) {
    student s{};
    std::stringstream ss(line);

    std::string idStr, courseStr, cfuStr, gradeStr, dateStr;

    // student_id,course,cfu,grade,exam_date
    if (!std::getline(ss, idStr, ',')) throw std::runtime_error("bad line");
    if (!std::getline(ss, courseStr, ',')) throw std::runtime_error("bad line");
    if (!std::getline(ss, cfuStr, ',')) throw std::runtime_error("bad line");
    if (!std::getline(ss, gradeStr, ',')) throw std::runtime_error("bad line"); // lo puoi ignorare
    if (!std::getline(ss, dateStr, ',')) throw std::runtime_error("bad line");

    s.id = std::stoi(idStr);
    s.esame = courseStr;
    s.cfu = std::stoi(cfuStr);
    s.data = dateStr;
    return s;
}

int main(int argc, char** argv){
    string dir = filesystem::current_path().parent_path();
    deque<student> students;

    string gradesPath = dir +"/data" "/grades.csv";
 
    cout << gradesPath << endl;

    string line;
    std::ifstream file(gradesPath);

    
    while(std::getline(file,line)){
        if(line[0] == 's'){
            continue;
        }else{
            students.push_back(parseStudent(line));
        }
        
    }
    for(student s : students){
        cout << s.id << " " << s.esame << " " << s.cfu << " " << s.data << endl;
    }

    return 0;
}