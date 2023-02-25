#pragma once
#include <string>
#include <memory>

#include "BmpExtractor.h"
#include "ConfigurationReader.hpp"
#include "Logger.hpp"
#include "MultipleBmpExtractor.h"
//#include "database/DataBaseCommunicator.h"

namespace am
{
    class AmApi
    {
    public:
        AmApi(const char *conf_path);
        analyze::algorithm::DescObjects compare(const std::string &base_img, const std::string &cmp_img);
        int compare_and_save_diff_img(const std::string &base_img, const std::string &cmp_img, std::string &out_diff_img);
        //void enable_database_reports(const char *db_name);

    private:
        std::shared_ptr<am::common::Logger> loggerPtr;
        extraction::MultipleBmpExtractor extractor;
        std::unique_ptr<analyze::algorithm::ObjectDetector> detector;

        std::string base_img_path;
        std::string cmp_img_path;
        const char *conf_path;
        //std::unique_ptr<database::DataBaseCommunicator> dbcPtr;
    };
}