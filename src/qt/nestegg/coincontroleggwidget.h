// Copyright (c) 2019 The NESTEGG developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLEGGWIDGET_H
#define COINCONTROLEGGWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlEggWidget;
}

class CoinControlEggWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlEggWidget(QWidget *parent = nullptr);
    ~CoinControlEggWidget();

private:
    Ui::CoinControlEggWidget *ui;
};

#endif // COINCONTROLEGGWIDGET_H
