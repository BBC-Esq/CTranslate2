#pragma once

#include "ctranslate2/layers/decoder.h"
#include "ctranslate2/sampling.h"

namespace ctranslate2 {

  void greedy_search(layers::Decoder& decoder,
                     layers::DecoderState& state,
                     const Sampler& sampler,
                     StorageView& sample_from,
                     const StorageView* candidates,
                     const StorageView* memory,
                     const StorageView* memory_lengths,
                     dim_t start_step,
                     dim_t end_token,
                     dim_t max_length,
                     dim_t min_length,
                     std::vector<std::vector<std::vector<size_t>>>& sampled_ids,
                     std::vector<std::vector<float>>& scores,
                     std::vector<std::vector<std::vector<std::vector<float>>>>* attention = nullptr);

  void beam_search(layers::Decoder& decoder,
                   layers::DecoderState& state,
                   const Sampler& sampler,
                   StorageView& sample_from,
                   const StorageView* candidates,
                   const StorageView* memory,
                   const StorageView* memory_lengths,
                   dim_t start_step,
                   dim_t end_token,
                   dim_t max_length,
                   dim_t min_length,
                   dim_t beam_size,
                   size_t num_hypotheses,
                   float length_penalty,
                   std::vector<std::vector<std::vector<size_t>>>& sampled_ids,
                   std::vector<std::vector<float>>& scores,
                   std::vector<std::vector<std::vector<std::vector<float>>>>* attention = nullptr);

  void initialize_decoder_with_prefix(const StorageView& start_ids,
                                      const std::vector<size_t>& prefix_ids,
                                      layers::Decoder& decoder,
                                      layers::DecoderState& state,
                                      const StorageView* memory,
                                      const StorageView* memory_lengths,
                                      std::vector<std::vector<float>>* prefix_attention);

}
