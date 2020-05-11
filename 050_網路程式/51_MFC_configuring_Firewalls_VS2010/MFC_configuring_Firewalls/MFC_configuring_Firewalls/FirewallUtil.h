#pragma once
#include <Netfw.h>
class CFirewallUtil
{
public:
    CFirewallUtil(void);
    ~CFirewallUtil(void);

    HRESULT IsFirewallEnabled(INetFwProfile* fwProfile, BOOL * pEnabled);
    HRESULT IsPortEnabled(INetFwProfile* fwProfile, BOOL *pEnabled, int iPort, bool bTCP);
    HRESULT SetPortEnabled(INetFwProfile* fwProfile, int iPort, bool bTCP, bool bEnable);

    HRESULT Initialize(INetFwProfile** fwProfile);
    void Uninitialize(INetFwProfile* fwProfile);

private:
    INetFwMgr* m_pFwMgr;
    INetFwPolicy* m_pFwPolicy;
};

