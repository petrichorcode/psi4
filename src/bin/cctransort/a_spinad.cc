/*
 * PSI4: an ab initio quantum chemistry software package
 *
 * Copyright (c) 2007-2015 The PSI4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <libdpd/dpd.h>

namespace psi { namespace cctransort {

void a_spinad(void)
{
  dpdbuf4 A;

  global_dpd_->buf4_init(&A, PSIF_CC_AINTS, 0, 0, 0, 0, 0, 0, "A <ij|kl>");
  global_dpd_->buf4_scmcopy(&A, PSIF_CC_AINTS, "A 2<ij|kl> - <ij|lk>", 2);
  global_dpd_->buf4_sort_axpy(&A, PSIF_CC_AINTS, pqsr, 0, 0, "A 2<ij|kl> - <ij|lk>", -1);
  global_dpd_->buf4_close(&A);
}

}} // namespace psi::cctranssort
