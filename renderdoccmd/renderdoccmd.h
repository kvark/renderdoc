/******************************************************************************
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Baldur Karlsson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

#pragma once

#include "3rdparty/cmdline/cmdline.h"

struct CaptureOptions;
struct TextureDisplay;

#ifdef __cplusplus
struct IReplayRenderer;
typedef IReplayRenderer ReplayRenderer;
#else
struct ReplayRenderer
#endif

struct Command
{
  virtual ~Command() {}
  virtual void AddOptions(cmdline::parser &parser) = 0;
  virtual int Execute(cmdline::parser &parser, const CaptureOptions &opts) = 0;
  virtual const char *Description() = 0;

  virtual bool IsInternalOnly() = 0;
  virtual bool IsCaptureCommand() = 0;
};

void add_command(const std::string &name, Command *cmd);
void add_alias(const std::string &alias, const std::string &command);

int renderdoccmd(int argc, char **argv);
int renderdoccmd(std::vector<std::string> &argv);

void readCapOpts(const std::string &str, CaptureOptions *opts);

// these must be defined in platform .cpps
void DisplayRendererPreview(ReplayRenderer *renderer, TextureDisplay &displayCfg, uint32_t width,
                            uint32_t height);
std::wstring GetUsername();