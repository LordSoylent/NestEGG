// Copyright (c) 2017-2020 The NESTEGG developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZEGGCONTROLDIALOG_H
#define ZEGGCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zegg/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZEggControlDialog;
}

class CZEggControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZEggControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZEggControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZEggControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZEggControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZEggControlDialog(QWidget *parent);
    ~ZEggControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZEggControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZEggControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZEGGCONTROLDIALOG_H
