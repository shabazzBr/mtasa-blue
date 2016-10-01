/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        core/CConnectManager.h
*  PURPOSE:     Header file for connect manager
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CCONNECTMANAGER_H
#define __CCONNECTMANAGER_H

#include <ctime>
#include <gui/CGUI.h>
#include <Serverbrowser/CServerInfo.h>

class CConnectManager
{
public:
                    CConnectManager     ( void );
                    ~CConnectManager    ( void );

    bool            Connect             ( const char* szHost, unsigned short usPort, const char* szNick, const char* szPassword, bool bNotifyServerBrowser = false );
    bool            Reconnect           ( const char* szHost, unsigned short usPort, const char* szPassword, bool bSave = true );

    bool            Abort               ( void );

    void            DoPulse             ( void );

    void            OnServerExists      ( void );

    static void     OpenServerFirewall ( in_addr Address, ushort usHttpPort = 80, bool bHighPriority = false );

    static bool     StaticProcessPacket ( unsigned char ucPacketID, class NetBitStreamInterface& bitStream );

    std::string     m_strLastHost;
    unsigned short  m_usLastPort;
    std::string     m_strLastPassword;
private:
    bool            Event_OnCancelClick ( CGUIElement * pElement );

    in_addr         m_Address;
    std::string     m_strHost;
    unsigned short  m_usPort;
    std::string     m_strNick;
    std::string     m_strPassword;
    bool            m_bIsDetectingVersion;
    bool            m_bIsConnecting;
    bool            m_bReconnect;
    bool            m_bSave;
    time_t          m_tConnectStarted;
    bool            m_bHasTriedSecondConnect;

    std::unique_ptr<GUI_CALLBACK>   m_pOnCancelClick;
    std::unique_ptr<CServerListItem> m_pServerItem;
    bool            m_bNotifyServerBrowser;

    bool CheckNickProvided ( const char* szNick );
};

#endif
