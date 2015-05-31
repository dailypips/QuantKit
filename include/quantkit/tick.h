#ifndef __QUANTKIT_TICK_H__
#define __QUANTKIT_TICK_H__

#include <quantkit/event.h>

namespace QuantKit {

class QUANTKIT_EXPORT TickEvent : public Event
{
protected:
    TickEvent(Event::Type type, const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Event(type, dateTime)
        , provider_id_(providerId)
        , instrument_id_(instrumentId)
        , price_(price)
        , size_(size)
    {}

    TickEvent(Event::Type type, const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : Event(type, dateTime)
        , exchange_time_(exchangeDateTime)
        , provider_id_(providerId)
        , instrument_id_(instrumentId)
        , price_(price), size_(size)
    {}

    explicit TickEvent(Event::Type type)
        : Event(type)
    {}

    TickEvent(const TickEvent& other) {
        type_ = other.type_;
        time_ = other.time_;
        exchange_time_ = other.exchange_time_;
        provider_id_ = other.provider_id_;
        instrument_id_ = other.instrument_id_;
        price_ = other.price_;
        size_ = other.size_;
    }

public:
    inline QDateTime exchangeDateTime() const { return exchange_time_; }
    inline void setExchangeDateTime(const QDateTime& exchangeDateTime) { exchange_time_ = exchangeDateTime; }

    inline unsigned char providerId() const { return provider_id_; }
    inline void setProviderId(unsigned int id) { provider_id_ = id; }

    inline unsigned char instrumentId() const { return instrument_id_; }
    inline void setInstrumentId(unsigned char id) { instrument_id_ = id; }

    inline double price() const { return price_; }
    inline void setPrice(double price) { price_ = price; }

    inline double size() const { return size_; }
    inline void setSize(double size) { size_ = size; }

protected:
    Q_DISABLE_COPY(Tick)
    QDateTime exchange_time_;
    unsigned char provider_id_;
    int instrument_id_;
    double price_;
    int size_;
};

class QUANTKIT_EXPORT AskEvent : public TickEvent
{
public:
    AskEvent(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : TickEvent(Event::Type::AskEvent, dateTime, providerId, instrumentId, price, size)
    {}

    AskEvent(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : TickEvent(Event::Type::AskEvent, dateTime, exchangeDateTime, providerId, instrumentId, price, size)
    {}

    AskEvent() : TickEvent(Event::Type::AskEvent) {}

    AskEvent(const AskEvent& other) : TickEvent(other) {}
};

class QUANTKIT_EXPORT BidEvent : public TickEvent
{
public:
    BidEvent(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : TickEvent(Event::Type::BidEvent, dateTime, providerId, instrumentId, price, size)
    {}

    BidEvent(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : TickEvent(Event::Type::BidEvent, dateTime, exchangeDateTime, providerId, instrumentId, price, size)
    {}

    BidEvent() : TickEvent(Event::Type::BidEvent) {}

    BidEvent(const BidEvent& other) : TickEvent(other) {}
};

class QUANTKIT_EXPORT TradeEvent : public TickEvent
{
public:
    TradeEvent(const QDateTime& dateTime, unsigned char providerId, int instrumentId, double price, int size)
        : TickEvent(Event::Type::TradeEvent, dateTime, providerId, instrumentId, price, size)
    {}

    TradeEvent(const QDateTime& dateTime, const QDateTime& exchangeDateTime, unsigned char providerId, int instrumentId, double price, int size)
        : TickEvent(Event::Type::TradeEvent, dateTime, exchangeDateTime, providerId, instrumentId, price, size)
    {}

    TradeEvent() : TickEvent(Event::Type::TradeEvent) {}

    TradeEvent(const TradeEvent& other) : TickEvent(other) {}
};

} // namespace QuantKit

Q_DECLARE_METATYPE(QuantKit::AskEvent)
Q_DECLARE_METATYPE(QuantKit::BidEvent)
Q_DECLARE_METATYPE(QuantKit::TradeEvent)

Q_DECLARE_METATYPE(QuantKit::AskEvent*)
Q_DECLARE_METATYPE(QuantKit::BidEvent*)
Q_DECLARE_METATYPE(QuantKit::TradeEvent*)

#endif // __QUANTKIT_TICK_H__
