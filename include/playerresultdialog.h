#ifndef PLAYERRESULTDIALOG_H
#define PLAYERRESULTDIALOG_H

#include <QDialog>
#include <QSpinBox>     // ✅ nødvendigt for QSpinBox
#include <QCheckBox>    // ✅ nødvendigt for QCheckBox

class PlayerResultDialog : public QDialog {
    Q_OBJECT

public:
    explicit PlayerResultDialog(QWidget *parent = nullptr);
    int getPlacement() const;
    bool getOnTime() const;
    void setPlacement(int p);
    void setOnTime(bool on);

private:
    QSpinBox* placementSpin;
    QCheckBox* onTimeCheck;
};

#endif // PLAYERRESULTDIALOG_H
