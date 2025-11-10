#include "CommandParser.hpp"
#include "../utils/Debug.hpp"


CommandParser::CommandParser(SensorManager& sm,
    std::vector<ActuatorInterface*> acts, 
    DataLogger& logger, 
    BluetoothManager& btSerial, 
    WifiManager& wfMan) : senMng(sm), actuator(acts), logger(logger), bt(btSerial), wf(wfMan) {}
void CommandParser::parseAnhExecute(const String& cmd)
{
    if(cmd.length() == 0) return;
    DBG("CommandParser","Parse: %s", cmd.c_str());
    std::vector<String> parts;

    int start = 0;
        for (int i = 0; i <= cmd.length(); ++i) {
        if (i == cmd.length() || cmd.charAt(i) == ' ') {
            String p = cmd.substring(start, i);
            p.trim();
            if (p.length() > 0) parts.push_back(p);
            start = i + 1;
        }
    }
    if(parts.size() == 0) return;
    String action = parts[0];
    action.toUpperCase();
    if(action == "READ_SENSOR" || action == "SENSOR")
    {
        String data = senMng.collectDataJson();
        bt.sendResponse(data);
        logger.log("READ SENSOR" + data);

    } else if ( action == "STATUS")
    {
        String status = "Uptime" + String(millis()/1000) + "s";
        bt.sendResponse(status);
        logger.log("STATUS requested");
    } else if ( action == "RET_LOG")
    {
        logger.clear();
        bt.sendResponse("OK: LOG Cleared");
        logger.log("LOG_CLEARED");
    }
    else if ( action == "PING")
    {
        bt.sendResponse("PONG");
    }
    else if ( action == "SET_LED")
    {
        if(parts.size() >= 2 )
        {
            ActuatorInterface* led = findActuatorName("LED");
            if(led)
            {
                led->setState(parts[1]);
                bt.sendResponse("OK");
            } else bt.sendResponse("ERR NO_LED");
        }
        else bt.sendResponse("ERR ARG");
    }
    else if ( action == "SET_MOTOR")
    {
        if(parts.size() >= 3) {
            ActuatorInterface* motor = findActuatorName("Motor");
            if(motor)
            {
                String param = parts[1] + " " + parts[2];
                motor->setState(param);
                bt.sendResponse("OK");
            }
            else bt.sendResponse("ERR NO_MOTOR");
        } else bt.sendResponse("ERR_ARG");
    }

    else if ( action == "UPLOAD")
    {
        String payload = cmd.substring(cmd.indexOf(' ') + 1);
        wf.sendtoClound(payload);
        bt.sendResponse("OK UPLOADED");
    } else bt.sendResponse("ERR UNKNOWN_CMD");

}

ActuatorInterface* CommandParser::findActuatorName(const String& name)
{
    for(const auto& a:actuator)
    {
        if(a->getName() == name) return a;
    }
    return nullptr;
}
