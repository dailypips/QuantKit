#ifndef __QUANTKIT_EVENT_H__
#define __QUANTKIT_EVENT_H__

#include <QDateTime>
#include <QMetaType>

#include <quantkit/quantkit_global.h>

namespace QuantKit {

class QUANTKIT_EXPORT Event
{
    Q_GADGET
    Q_ENUMS(Type)
public:
    enum class Type {
        UnknowEvent = 0,
        AskEvent,
        BidEvent,
        TradeEvent
    };

    virtual ~Event() {}

    inline Event::Type type() const {
        return type_;
    }

    inline QDateTime time() const {
        return time_;
    }

    inline void setTime(const QDateTime& time) {
        time_ = time;
    }

protected:
    Q_DISABLE_COPY(Event)

    explicit Event(Event::Type type)
        : type_(type)
    {}

    Event(Event::Type type, const QDateTime& time)
        : type_(type), time_(time)
    {}

    Event::Type type_;
    QDateTime time_;
};

} // namespace 

Q_DECLARE_METATYPE(QuantKit::Event*)

#endif // __QUANTKIT_EVENT_H__
