/*
 * Copyright (c) 2018, Aetf <aetf at unlimitedcodeworks dot xyz>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice,
 *       this list of conditions and the following disclaimer in the documentation
 *       and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PLASMA_POTD_SPOTLIGHT_PROVIDER_H
#define PLASMA_POTD_SPOTLIGHT_PROVIDER_H

#include <QImage>
#include <plasma/potdprovider/potdprovider.h>

class KJob;
/**
 * This class provides the image from Microsoft's Windows Spotlight
 * URL is obtained from:
 * https://github.com/KoalaBR/spotlight/blob/3164a43684dcadb751ce9a38db59f29453acf2fe/spotlightprovider.cpp#L17
 * https://github.com/ORelio/Spotlight-Downloader
 */
class SpotlightProvider : public PotdProvider
{
    Q_OBJECT
public:
    /**
     * Creates a new Spotlight provider.
     *
     * @param date The date for which the image shall be fetched.
     * @param parent The parent object.
     */
    SpotlightProvider(QObject *parent, const QVariantList &args);

    /**
     * Destroys the Spotlight provider.
     */
    ~SpotlightProvider() override;

    /**
     * Returns the requested image.
     *
     * Note: This method returns only a valid image after the
     *       finished() signal has been emitted.
     */
    QImage image() const override;

private:
    void pageRequestFinished(KJob *job);
    void imageRequestFinished(KJob *job);

private:
    QImage m_image;
};

#endif // PLASMA_POTD_SPOTLIGHT_PROVIDER_H