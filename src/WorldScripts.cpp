#include "ScriptMgr.h"
#include "ChatTransmitter.h"

namespace ModChatTransmitter
{
    class WorldScripts : public WorldScript
    {
    public:
        WorldScripts() : WorldScript("ModChatTransmitterWorldScripts")
        { }

        void OnShutdown() override
        {
            ChatTransmitter::Instance().Stop();
        }

        void OnUpdate(uint32) override
        {
            ChatTransmitter::Instance().Update();
        }
    };

    void AddWorldScripts()
    {
        new WorldScripts();
    }
}
