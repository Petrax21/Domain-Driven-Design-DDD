# Webview Telefon Rehberinde DDD kullanımı

Bu proje, Domain-Driven Design (DDD) prensiplerine dayalı bir uygulama örneğidir. DDD, karmaşık yazılım projelerinde iş alanını (domain) modellemeye odaklanarak, yazılımın iş hedefleriyle uyumlu olmasını sağlar.

## İçindekiler

- [Nedir DDD?](#nedir-ddd)
- [DDD Prensipleri](#ddd-prensipleri)
- [Proje Yapısı](#proje-yapısı)
- [Kullanım](#kullanım)
- [Katkıda Bulunma](#katkıda-bulunma)
- [Lisans](#lisans)

## Nedir DDD?

Domain-Driven Design, yazılım geliştirme sürecinde iş alanının karmaşıklığını yönetmeyi amaçlar. Eric Evans tarafından tanıtılan bu yaklaşım, yazılımın iş hedefleriyle uyumlu olmasını sağlayan bir dizi teknik ve prensip içerir. DDD, iş problemlerini anlamak ve bu problemleri çözmek için doğru modelleme yapmayı teşvik eder.

## DDD Prensipleri

1. **Domain**: Yazılımın odaklandığı iş alanıdır. İş süreçlerini, kurallarını ve gereksinimlerini kapsar.
2. **Ubiquitous Language (Ortak Dil)**: Geliştiriciler ve iş paydaşları arasında ortak bir dil kullanmak, iletişimi ve iş birliğini artırır.
3. **Bounded Context (Sınırlı Bağlam)**: İş alanının farklı bölümleri arasında net sınırlar çizerek, karmaşayı azaltır.
4. **Entities**: Kimlikleri ile tanımlanan nesnelerdir. Durumları değişebilir ve yaşam döngüleri boyunca takip edilir.
5. **Value Objects (Değer Nesneleri)**: Kimliği olmayan, yalnızca değerleriyle tanımlanan nesnelerdir.
6. **Aggregates**: İş kurallarını uygulamak ve tutarlılığı sağlamak için bir araya getirilen nesne gruplarıdır.
7. **Repositories**: Veri erişim katmanı, verilerin depolanması ve alınması için kullanılır.

## Proje Yapısı

Proje, DDD prensiplerine uygun olarak aşağıdaki gibi yapılandırılmıştır:

├── application  
│ └── service.hpp  
├── cmake-build-debug  
├── domain  
│ ├── contact  
│ │ ├── contact.hpp  
│ │ ├── contact-factory.hpp  
│ │ ├── contact-repository.hpp  
│ │ └── contact-service.hpp  
├── json  
├── libs  
│ └── webview  
├── main.cpp  
├── CMakeLists.txt  
├── embedded_files.h  
└── vcpkg.json  


- **application**: Uygulama katmanı, kullanıcıdan gelen istekleri işler ve iş mantığını uygular.
- **domain**: İş mantığını ve kurallarını içerir.
- **cmake-build-debug**: CMake ile oluşturulmuş derleme dosyalarını içerir.
- **json**: JSON dosyaları ve ile ilgili veri yapıları.
- **libs**: Kullanılan kütüphaneler.
- **main.cpp**: Uygulamanın giriş noktası.
- **CMakeLists.txt**: CMake yapılandırma dosyası.
- **embedded_files.h**: Gömülü dosyalar için başlık dosyası.
- **vcpkg.json**: Vcpkg yapılandırma dosyası.

