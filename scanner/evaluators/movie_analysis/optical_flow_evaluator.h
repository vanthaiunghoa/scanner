#pragma once

#include "scanner/eval/evaluator.h"
#include "scanner/eval/evaluator_factory.h"
#include "scanner/util/opencv.h"

#ifdef HAVE_CUDA
#include "scanner/util/cuda.h"
#endif

namespace scanner {

class OpticalFlowEvaluator : public Evaluator {
 public:
  OpticalFlowEvaluator(DeviceType device_type);
  ~OpticalFlowEvaluator();

  void reset() override;

  void evaluate(const std::vector<std::vector<u8*>>& input_buffers,
                const std::vector<std::vector<size_t>>& input_sizes,
                std::vector<std::vector<u8*>>& output_buffers,
                std::vector<std::vector<size_t>>& output_sizes) override;

 private:
  DeviceType device_type_;
  void* initial_frame_;
};

class OpticalFlowEvaluatorFactory : public EvaluatorFactory {
 public:
  OpticalFlowEvaluatorFactory(DeviceType device_type);

  EvaluatorCapabilities get_capabilities() override;

  std::vector<std::string> get_output_names() override;

  Evaluator* new_evaluator(const EvaluatorConfig& config) override;

 private:
  DeviceType device_type_;
};
}