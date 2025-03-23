//442881 Ammar Daas
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip> 
#include <locale.h>
#include <vector>
#include <sstream>
using namespace std;

const string TakimFileName = "takimlar";
const string TakimReaslteFile = "fikstur";


class clsFootBall_Teams {
    string _TeamName = "";
    short _Number_Of_Matches_Played = 0;
    short _Number_Of_wins = 0;
    short _Number_Of_Draw = 0;
    short _Number_Of_Defeats = 0;
    short _goal_Scored = 0;
    short _Conceded_Scored = 0;
    short _AV = 0;
    short _Point = 0;
    bool _Will_The_Team_Play = false;
    short _NumberOfMachesAtHome = 0;
    short _NumberOfMachesAt_opponents_field = 0;

    vector <string> _TheTeams_between_playing_with_it;

public:
    void  setName(string TeamName) {
        _TeamName = TeamName;
    }

    void getTeamName(string name) {
        _TeamName = name;
    }

    string getTeamName() {
        return _TeamName;
    }
    short  getNumber_Of_Matches_Played() {
        return _Number_Of_Matches_Played;
    }
    short  getNumber_Of_wins() {
        return _Number_Of_wins;
    }
    short  getNumber_Of_Draw() {
        return _Number_Of_Draw;
    }
    short  getNumber_Of_Defeats() {
        return _Number_Of_Defeats;
    }
    short  getgoal_Scored() {
        return _goal_Scored;
    }
    short  getConceded_Scored() {
        return _Conceded_Scored;
    }
    short  getAV() {
        CalculateAV();
        return _AV;
    }
    short  getPoint() {
        return _Point;
    }
    short GetNumberOfMachesAtHome() {
        return _NumberOfMachesAtHome;
    }
    short Get_NumberOfMachesAt_opponents_field() {
        return _NumberOfMachesAt_opponents_field;
    }


    void Add_a_team_played_with(string TeamName) {
        _TheTeams_between_playing_with_it.push_back(TeamName);
        if (_TheTeams_between_playing_with_it.size() > 18) {
            _TheTeams_between_playing_with_it.clear();
        }
    }

    void AddNewGameAtHome() {
    
        _NumberOfMachesAtHome++;
    }
    void AddNewGameAt_opponents_field() {
    
        _NumberOfMachesAt_opponents_field++;
    }
    void AddScoredGol(short Gol) {
        _goal_Scored += Gol;
    }

    void AddConcededGol(short Gol) {
        _Conceded_Scored += Gol;
    }

    void AddMatchPlayed() {
        _Number_Of_Matches_Played++;
    }

    void AddWin() {
        _Number_Of_wins++;
        _Point += 3;
    }

    void AddDraw() {
        _Number_Of_Draw++;
        _Point += 1;
    }

    void AddDefeat() {
        _Number_Of_Defeats++;
    }

    void CalculateAV() {
        _AV = _goal_Scored - _Conceded_Scored;
    }

    bool IsThisTeam(string Name) {
        return (_TeamName == Name);
    }

    void The_Team_PlayThisWeek() {
        _Number_Of_Matches_Played++;
        _Will_The_Team_Play = true;
    }

    bool Is_teams_who_played_with_her(string TeamName) {
        for (short i = 0; i < _TheTeams_between_playing_with_it.size(); i++)
        {

            if (_TheTeams_between_playing_with_it[i] == TeamName) {
                return true;
            }
        }return false;
    }
};

class clsTaple {
public:
    static string _PrintSonucTaple() {
        std::stringstream ss;

        ss << "\n\t\t" << std::left << std::setw(45) << "Team Name"
            << std::right << std::setw(15) << "O"
            << std::right << std::setw(8) << "G"
            << std::right << std::setw(8) << "B"
            << std::right << std::setw(8) << "M"
            << std::right << std::setw(8) << "A"
            << std::right << std::setw(8) << "Y"
            << std::right << std::setw(8) << "AV"
            << std::right << std::setw(8) << "P"
            << std::endl;

        ss << "\t\t" << setfill('-') << std::setw(88) << "-" <<setfill(' ') << endl;

        return ss.str();
    }

    static string PrintResult(clsFootBall_Teams Teams) {
        std::stringstream ss;

        if (!Teams.getTeamName().empty()) {
            ss << "\t\t" << std::left << std::setw(35) << Teams.getTeamName()
                << std::right << std::setw(10) << Teams.getNumber_Of_Matches_Played()
                << std::right << std::setw(8) << Teams.getNumber_Of_wins()
                << std::right << std::setw(8) << Teams.getNumber_Of_Draw()
                << std::right << std::setw(8) << Teams.getNumber_Of_Defeats()
                << std::right << std::setw(8) << Teams.getgoal_Scored()
                << std::right << std::setw(8) << Teams.getConceded_Scored()
                << std::right << std::setw(8) << Teams.getAV()
                << std::right << std::setw(8) << Teams.getPoint()
                << std::endl;
        }
        else {
            ss << "Team data is invalid!";
        }

        return ss.str();
    }
};
void ReadTeamsFile(string TakimsNAme[19]) {
    fstream File;
    File.open(TakimFileName, ios::in);
    if (File.is_open())
    {
        string line;
        short pos = 0;
        while (getline(File, line)) {
            TakimsNAme[pos] = line;
            pos++;
        }
    }
    else {
        cout << "Dont can Open File\n";
    }

}

short RandomGol(int from, int to) {
    short randgol;
    randgol = rand() % (to - from + 1) + from;
    return randgol;

}

string RandomVS(string TakimName[19]) {
    short RandTakim;
    RandTakim = RandomGol(1, 19) - 1;
    while (TakimName[RandTakim] == " ") {
        RandTakim = RandomGol(1, 19) - 1;
    }

    return TakimName[RandTakim];
}
void Create_Teams(string TakimsName[19], clsFootBall_Teams Teams[19])
 {
    for (short i = 0; i < 19; i++)
    {
        if (TakimsName[i] != "") {
            Teams[i].setName(TakimsName[i]);
        }
    }
}

void Delete_Team(string TeamsName[19], string& Team) {
    for (short i = 0; i < 19; i++)
    {
        if (TeamsName[i] == Team) {
            TeamsName[i] = " ";
        }

    }
}

clsFootBall_Teams FindObjectTeam(string TeamName, clsFootBall_Teams Teams[19]) {
    for (short i = 0; i < 19; i++)
    {
        if (Teams[i].IsThisTeam(TeamName)) {
            return Teams[i];
        }

    }clsFootBall_Teams emptyClass;
    emptyClass.getTeamName(" ");
    return  emptyClass;
}

void SaveResult(clsFootBall_Teams Teams[19], clsFootBall_Teams ThisTeam) {
    string TeamName = ThisTeam.getTeamName();
    for (short i = 0; i < 19; i++)
    {
        if (Teams[i].IsThisTeam(TeamName)) {
            Teams[i] = ThisTeam;
            break;
        }

    }
}

void Refeer(clsFootBall_Teams& Team1, clsFootBall_Teams& Team2) {
    Team1.The_Team_PlayThisWeek();
    Team2.The_Team_PlayThisWeek();

    Team1.AddNewGameAtHome();
    Team2.AddNewGameAt_opponents_field();

    short Team1Gols = RandomGol(0, 5);
    short Team2Gols = RandomGol(0, 3);

    Team1.AddScoredGol(Team1Gols);
    Team1.AddConcededGol(Team2Gols);

    Team2.AddScoredGol(Team2Gols);
    Team2.AddConcededGol(Team1Gols);

    if (Team1Gols > Team2Gols)
    {
        Team1.AddWin();
        Team2.AddDefeat();
    }
    if (Team1Gols < Team2Gols)
    {
        Team2.AddWin();
        Team1.AddDefeat();
    }
    if (Team1Gols == Team2Gols)
    {
        Team1.AddDraw();
        Team2.AddDraw();
    }

    Team2.Add_a_team_played_with(Team1.getTeamName());

}

void CopyArray(string BasicArry[19], string CopyArray[19]) {
    for (short i = 0; i < 19; i++)
    {
        CopyArray[i] = BasicArry[i];
    }
}

bool Selecting_Team(string TakimsName[19], clsFootBall_Teams Teams[19], string ThisWeekPlayedTeams[9], string& This_Week_Dont_Plaayed_Team) {
    static short WeekNumber = 1;
    string CopyTakimsName[19];
    string Team1_Name;
    string Team2_Name;
    clsFootBall_Teams Team1, Team2;
    //NOT:Team1=iç saha   Takim2= deplasman
    CopyArray(TakimsName, CopyTakimsName);
    CopyTakimsName[(WeekNumber - 1) % 19] = " ";
    int attempts = 0;
    for (short i = 0; i < 9; i++)
    {
        
        
         
        Team1_Name = RandomVS(CopyTakimsName);
        Team1 = FindObjectTeam(Team1_Name, Teams);
        while (Team1.GetNumberOfMachesAtHome() > 19 || Team1.getTeamName() == "") {
            Team1_Name = RandomVS(CopyTakimsName);
            Team1 = FindObjectTeam(Team1_Name, Teams);
        }
        Delete_Team(CopyTakimsName, Team1_Name);

        Team2_Name = RandomVS(CopyTakimsName);
        Team2 = FindObjectTeam(Team2_Name, Teams);
        while ( Team2.Get_NumberOfMachesAt_opponents_field() > 19 || Team2.Is_teams_who_played_with_her(Team1_Name) || Team2.getTeamName() == "") {
            Team2_Name = RandomVS(CopyTakimsName);
            Team2 = FindObjectTeam(Team2_Name, Teams);
            attempts++;
            if (attempts > 19) { 
                return false;
            }
        }

        Refeer(Team1, Team2);
        SaveResult(Teams, Team1);
        SaveResult(Teams, Team2);
        ThisWeekPlayedTeams[i] = Team1_Name + " VS " + Team2_Name;
        Delete_Team(CopyTakimsName, Team2_Name);
    }
    This_Week_Dont_Plaayed_Team = TakimsName[(WeekNumber - 1) % 19];
    WeekNumber++;
    return true;
}

void PrintTheTable(string ThisWeekPlayedTeams[9], string& This_Week_Dont_Plaayed_Team) {
    for (short i = 0; i < 9; i++)
    {
        cout << ThisWeekPlayedTeams[i] << endl;

    }
    cout << "This Team Didint Play this Week : " << This_Week_Dont_Plaayed_Team << endl;

}

bool SaveResultInFile(clsFootBall_Teams Teams[19]) {
    fstream File;
    File.open(TakimReaslteFile, ios::out);

    if (File.is_open())
    {
        File << clsTaple::_PrintSonucTaple();
        for (short i = 0; i < 19; i++)
        {
            File << clsTaple::PrintResult(Teams[i])<<endl;
            
        }File.close();
        return true;

    }
    else {
        cout << "Dont can Open File\n";
    }
    return false;
}

void ReadAndPrintFrom_FiksturFile(string dosyaAdi= TakimReaslteFile) {
   ifstream dosya(dosyaAdi); 

    if (!dosya.is_open()) {
        cerr << "File Dont Open " << dosyaAdi <<endl;
        return;
    }

   string satir;
    while (getline(dosya, satir)) { 
       cout << satir << endl; 
    }

    dosya.close(); 
     
}

int main()
{
    setlocale(LC_ALL, "tr_TR.UTF-8");
    srand((unsigned)time(NULL));
    string TakimsName[19];
    ReadTeamsFile(TakimsName);
    clsFootBall_Teams Teams[19];
    Create_Teams(TakimsName, Teams);
    string ThisWeekPlayedTeams[9];
    string This_Week_Dont_Plaayed_Team = "";
    string YorN,YorN_ForLoop="y";
    ReadAndPrintFrom_FiksturFile();
    cout << "The data inside the file will be deleted . "<<endl<<endl;


    cout << "Do You Want Print Evrey Result ? (y / n)  ";
    cin >> YorN;
    for (short i = 0; i < 38; i++)
    {
      
        if (Selecting_Team(TakimsName, Teams, ThisWeekPlayedTeams, This_Week_Dont_Plaayed_Team) == false) {
            Selecting_Team(TakimsName, Teams, ThisWeekPlayedTeams, This_Week_Dont_Plaayed_Team);
        }

        if (i==11)
        {
            i = 11;
        }
        if (toupper(YorN[0]) == 'Y')
        {
               if (toupper(YorN_ForLoop[0]) == 'Y') {
                cout << endl << "\t\tWEEK " << i + 1 << endl << endl;
                PrintTheTable(ThisWeekPlayedTeams, This_Week_Dont_Plaayed_Team);
            }

         
            if (i != 37)
            {
                cout << "Do You Want Print the Week " << i + 2 << " : (y / n)  ";
                cin >> YorN_ForLoop;
            }

        }


    }
    if (SaveResultInFile(Teams))
    {
        
        cout << "The Match History is Stored In The File ";
    }
    else
        cout << "The Match History is not Stored In The File";

    return 0;
}
