/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

namespace ams::kern {

    class KInterruptTask;

    class KInterruptHandler {
        public:
            virtual KInterruptTask *OnInterrupt(s32 interrupt_id) = 0;
    };

    class KInterruptTask : public KInterruptHandler {
        private:
            KInterruptTask *next_task;
        public:
            constexpr ALWAYS_INLINE KInterruptTask() : next_task(nullptr) { /* ... */ }

            ALWAYS_INLINE KInterruptTask *GetNextTask() const {
                return this->next_task;
            }

            ALWAYS_INLINE void SetNextTask(KInterruptTask *t) {
                this->next_task = t;
            }

            virtual void DoTask() = 0;
    };

}