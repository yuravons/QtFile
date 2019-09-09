#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("input.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout << "no file" << endl;
        return 0;
    }
    QString line;
    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine();
    }

    cout << line.toStdString() << endl;
    string str;
    cout << "Enter sentences: " << endl;
    cin >> str;

    QFile file1("output.txt");
    if (!file1.open(QIODevice::WriteOnly | QIODevice::Append)) {
        cout << "no file" << endl;
        return 0;
    }
    QTextStream out(&file1);
    out << "Md5():" << str.c_str() << endl;
    file1.close();
    file.close();
    return a.exec();
}

