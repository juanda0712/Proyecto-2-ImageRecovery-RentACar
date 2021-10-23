//
// Created by eduardo on 22/10/21.
//

#ifndef IMAGE_RECOVERY_INDIVIDUAL_H
#define IMAGE_RECOVERY_INDIVIDUAL_H

#include <vector>
#include <QColor>

using namespace std;

class Individual {
private:
    int id;
    QColor* color;
public:
    Individual(int id1);
    vector<int> information;
    int getId() const;
};


#endif //IMAGE_RECOVERY_INDIVIDUAL_H
