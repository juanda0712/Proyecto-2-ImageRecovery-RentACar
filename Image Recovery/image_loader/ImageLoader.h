//
// Created by eduardo on 19/10/21.
//

#ifndef IMAGE_RECOVERY_IMAGELOADER_H
#define IMAGE_RECOVERY_IMAGELOADER_H

#include <QPixmap>
#include <QLabel>
#include <QString>
#include <QMainWindow>

class ImageLoader {
public:
    static void loadImage(QString filepath, QMainWindow *parent);
};


#endif //IMAGE_RECOVERY_IMAGELOADER_H
