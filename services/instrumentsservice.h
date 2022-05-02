#ifndef INSTRUMENTSSERVICE_H
#define INSTRUMENTSSERVICE_H

#include <QObject>
#include "customservice.h"
#include <grpcpp/grpcpp.h>
#include "instruments.grpc.pb.h"
#include "servicereply.h"

using grpc::Channel;
using namespace tinkoff::public1::invest::api::contract::v1;

class Instruments: public CustomService
{
    Q_OBJECT
    Q_CLASSINFO("instruments", "Instruments Service")

public:  
    Instruments(std::shared_ptr<Channel> channel, const QString &token);
    ~Instruments();

public slots:
    //Метод получения расписания торгов торговых площадок.
    ServiceReply TradingSchedules(const std::string &exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    //Метод получения облигации по её идентификатору.
    ServiceReply BondBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
//    //Метод получения списка облигаций.
    ServiceReply Bonds(InstrumentStatus instrumentStatus);
    //Метод получения графика выплат купонов по облигации
    ServiceReply GetBondCoupons(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    //Метод получения валюты по её идентификатору.
    ServiceReply CurrencyBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    //Метод получения списка валют.
    ServiceReply Currencies(InstrumentStatus instrumentStatus);
    //Метод получения инвестиционного фонда по его идентификатору.
    ServiceReply EtfBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    //Метод получения списка инвестиционных фондов.
    ServiceReply Etfs(InstrumentStatus instrumentStatus);
    //Метод получения фьючерса по его идентификатору.
    ServiceReply FutureBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    //Метод получения списка фьючерсов.
    ServiceReply Futures(InstrumentStatus instrumentStatus);
    //Метод получения акции по её идентификатору.
    ServiceReply ShareBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    //Метод получения списка акций.
    ServiceReply Shares(InstrumentStatus instrumentStatus);
    //Метод получения накопленного купонного дохода по облигации.
    ServiceReply GetAccruedInterests(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    //Метод получения размера гарантийного обеспечения по фьючерсам.
    ServiceReply GetFuturesMargin(const std::string  &figi);
    //Метод получения основной информации об инструменте.
    ServiceReply GetInstrumentBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    //Метод для получения событий выплаты дивидендов по инструменту.
    ServiceReply GetDividends(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    //Метод получения актива по его идентификатору.
    ServiceReply GetAssetBy(const std::string  &id);
    //Метод получения списка активов.
    ServiceReply GetAssets();
    //Метод получения избранных инструментов.
    ServiceReply GetFavorites();
    //Метод редактирования избранных инструментов.
    ServiceReply EditFavorites(const std::vector<EditFavoritesRequestInstrument> &instruments, EditFavoritesActionType actionType);

private:
    std::unique_ptr<InstrumentsService::Stub> m_instrumentsService;

};

#endif // INSTRUMENTSSERVICE_H
