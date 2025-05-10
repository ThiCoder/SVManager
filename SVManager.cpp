#include<bits/stdc++.h>

using namespace std;

struct sv {
    string HoTen;
    int mssv;
    int khoa;
};

vector<sv> SinhVien;
vector<sv>::iterator it;
// Khối giao diện
void MainUI() {
    cout << "==========QUAN LI SINH VIEN==========" << endl;
    cout << "||1. Them sinh vien                ||" << endl;
    cout << "||2. Xoa sinh vien                 ||" << endl;
    cout << "||3. Sua thong tin sinh vien"<< endl;
    cout << "||4. Hien thi danh sach sinh vien  ||" << endl;
    cout << "||=> Nhan 0 de quay lai            ||" << endl;
    cout << "=====================================" << endl;
}

void modifyUI() {
    cout << "1. Sua Ho va Ten" << endl;
    cout << "2. Sua Ma so sinh vien" << endl;
    cout << "3. Sua nam hoc" << endl;
    cout << "Nhan 0 de quay lai" << endl;
}

void secodeUI() {
    cout << "Nhap MSSV: " <<endl;
}
// Khối xử lý
sv addSV() {
    sv person;
    cout << "Nhap Ho va Ten: "<<endl;
    cin.ignore();
    getline(cin ,person.HoTen);
    cout<< "Nhap Ma so sinh vien: "<<endl;
    cin >> person.mssv;
    cout<< "Nhap nam hoc: " << endl;
    cin >> person.khoa;
    return person;
}

void displaySV() {
    int i = 1;
    for (sv x : SinhVien) {
        cout<< i << endl;
        cout<< "Ho va ten: " << x.HoTen << endl;
        cout<< "Mssv: " << x.mssv << endl;
        cout<< "Sinh vien nam " << x.khoa << endl;
        i++;
    }
    cout << "=> Nhan 0 de quay lai" << endl;
}

vector<sv>::iterator SVLocation(int id) {
    for (it = SinhVien.begin(); it != SinhVien.end(); it++) 
        if (it->mssv == id) return it;
    return it;
}


int main() {
    int runcode;
    int se_code;// search code


    while (true)
    {
        system("cls");
        MainUI();
        cin >> runcode;
        if (runcode == 0) break;

        
        switch (runcode)
        {   //Them sinh vien
            case 1:
            {
                system("cls");
                SinhVien.push_back(addSV());
                break;
            }
            //Xoa sinh vien
            case 2:
            { 
                system("cls");
                secodeUI();
                cin >> se_code;
                SinhVien.erase(SVLocation(se_code));
                break;
            }
            //Sua sinh vien
            case 3:
            {
                system("cls");
                secodeUI();
                cin >> se_code;
                // Còn thiếu đoạn kiểm tra mssv
                while (true) 
                {
                    system("cls");
                    modifyUI();
                    cin>> runcode;
                    if (runcode == 0) break;

                    switch (runcode)
                    {
                        case 1: 
                        {
                            cout << "Nhap ten: " << endl;
                            cin.ignore();
                            getline(cin ,SVLocation(se_code)->HoTen);
                            break;
                        }
                        case 2:
                        {
                            cout << "Nhap mssv: " << endl;
                            cin >> SVLocation(se_code)->mssv;
                            break;
                        }
                        case 3:
                        {
                            cout << "Nhap nam hoc: " << endl;
                            cin >> SVLocation(se_code)->khoa;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                system("cls");
                displaySV();
                cin >> runcode;
                if (runcode == 0) break;
                break;
            }
        }
    }
    return 0;
}